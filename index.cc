#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New("test to return").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("test").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(nodeTesterAddon, Init)