
#include "pch.hpp"
#include "Engine.hpp"
#include <memory>
#include "test.hpp"

NovaEngine::Engine::Engine(const char* cwd)
{
    using namespace v8;

	printf("%s\n", cwd);
	
    std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform(1);
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();
    
	// Create a new Isolate and make it the current one.
    v8::Isolate::CreateParams create_params;
    
	create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();

    v8::Isolate* isolate = v8::Isolate::New(create_params);
    {
        v8::Isolate::Scope isolate_scope(isolate);
        v8::HandleScope handle_scope(isolate);
        v8::Local<v8::Context> context = v8::Context::New(isolate);
        v8::Context::Scope context_scope(context);
        v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, "'Hello' + ', World!'", v8::NewStringType::kNormal).ToLocalChecked();
        v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();
        v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
        v8::String::Utf8Value utf8(isolate, result);
		#ifdef _WIN32
    	MessageBoxA(NULL, *utf8, *utf8, MB_OK);
		#else
		printf("%s\n", *utf8);
		#endif
	}

	#ifdef _WIN32
	char buf[16] = {};
	memset(buf, '\0', 16);
    _itoa_s<16>(test(), buf, 10);
	MessageBoxA(NULL, "", buf, MB_OK);
	memset(buf, '\0', 16);
    _itoa_s<16>(test(), buf, 10);
	MessageBoxA(NULL, "", buf, MB_OK);
	memset(buf, '\0', 16);
    _itoa_s<16>(test(), buf, 10);
	MessageBoxA(NULL, "", buf, MB_OK);
	memset(buf, '\0', 16);
    _itoa_s<16>(test(), buf, 10);
	MessageBoxA(NULL, "", buf, MB_OK);
	#else
	printf("%i\n", test());
	printf("%i\n", test());
	printf("%i\n", test());
	printf("%i\n", test());
	#endif
		

    // Dispose the isolate and tear down V8.
    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();
    delete create_params.array_buffer_allocator;
}
