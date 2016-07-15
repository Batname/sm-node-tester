#include <nan.h>
#include <iostream>

void CreateObject(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::HeapStatistics heap_statistics = v8::HeapStatistics();
  Nan::GetHeapStatistics(&heap_statistics);

  v8::Local<v8::Object> obj = Nan::New<v8::Object>();
  obj->Set(Nan::New("heapSizeLimit").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.heap_size_limit()));
  obj->Set(Nan::New("totalAvailableSize").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.total_available_size()));
  obj->Set(Nan::New("totalHeapSize").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.total_heap_size()));
  obj->Set(Nan::New("totalHeapSizeExecutable").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.total_heap_size_executable()));
  obj->Set(Nan::New("totalPhysicalSize").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.total_physical_size()));
  obj->Set(Nan::New("usedHeapSize").ToLocalChecked(), Nan::New<v8::Integer>((int)heap_statistics.used_heap_size()));

  info.GetReturnValue().Set(obj);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  module->Set(Nan::New("exports").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(CreateObject)->GetFunction());
}

NODE_MODULE(nodeTesterAddon, Init)