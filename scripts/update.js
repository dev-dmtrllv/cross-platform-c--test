const { parseStringPromise, Builder } = require("xml2js");

const fs = require("fs");
const path = require("path");

const readdirRecursive = (p) =>
{
	const result = [];
	fs.readdirSync(p).forEach((d) => 
	{
		const np = path.resolve(p, d);
		if (fs.statSync(np).isDirectory())
			result.push(...readdirRecursive(np));
		else
			result.push(np);
	});
	return result;
}

const getSources = (p) => readdirRecursive(path.join(p, "src"));
const getIncludes = (p) => readdirRecursive(path.join(p, "include"));

const update = async (name) =>
{
	const p = path.resolve(__dirname, "..", name);
	const srcs = getSources(p);
	const includes = getIncludes(p);

	const xml = fs.readFileSync(path.resolve(p, path.basename(p) + ".vcxproj"), { encoding: "utf-8" });
	let o = await parseStringPromise(xml);
	for (let t of o["Project"]["ItemGroup"])
	{
		const k = Object.keys(t)
		if (k.includes("ClInclude"))
		{
			t["ClInclude"].forEach(c => 
			{
				const filePath = path.resolve(p, c["$"]["Include"]);
				if (includes.indexOf(filePath) > -1)
					includes.splice(includes.indexOf(filePath), 1);
			});
		}
		else if (k.includes("ClCompile"))
		{
			t["ClCompile"].forEach(c => 
			{
				const filePath = path.resolve(p, c["$"]["Include"]);
				if (srcs.indexOf(filePath) > -1)
					srcs.splice(srcs.indexOf(filePath), 1);
			});
		}
	}

	for (let t of o["Project"]["ItemGroup"])
	{
		const k = Object.keys(t)
		if (k.includes("ClInclude"))
		{
			t["ClInclude"].push(...includes.map(i => { return { "$": { Include: i.substring(p.length + 1, i.length) } } }));
			// console.log(t["ClInclude"]);
		}
		else if (k.includes("ClCompile"))
		{
			t["ClCompile"].push(...srcs.map(i => { return { "$": { Include: i.substring(p.length + 1, i.length) } } }));
			// console.log(t["ClCompile"]);
		}
	}

	const b = new Builder();
	const xmlStr = b.buildObject(o);
	fs.writeFileSync(`${path.resolve(p, name + ".vcxproj")}`, xmlStr);
}


update("NovaEngine");
update("TestGame");
