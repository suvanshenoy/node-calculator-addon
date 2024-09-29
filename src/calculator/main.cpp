#include "calculator.hpp"
#include <memory>
#include <napi.h>

Napi::Object CreateCalculator(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::Object calculator = Napi::Object::New(env);

  // Create a shared pointer for the Calculator (not needed for static methods)
  // You can keep it if you're planning to extend functionality later
  // auto calc = std::make_shared<Calculator<double>>();

  calculator.Set("add",
                 Napi::Function::New(
                     env, [](const Napi::CallbackInfo &info) -> Napi::Value {
                       Napi::Env env = info.Env();
                       if (info.Length() < 2 || !info[0].IsNumber() ||
                           !info[1].IsNumber()) {
                         Napi::TypeError::New(env, "Number arguments expected")
                             .ThrowAsJavaScriptException();
                         return env.Null();
                       }
                       // Get values as integral types (e.g., int32_t)
                       int32_t a = info[0].As<Napi::Number>().Int32Value();
                       int32_t b = info[1].As<Napi::Number>().Int32Value();
                       return Napi::Number::New(env, Calculator::add(a, b));
                     }));

  calculator.Set("subtract",
                 Napi::Function::New(
                     env, [](const Napi::CallbackInfo &info) -> Napi::Value {
                       Napi::Env env = info.Env();
                       if (info.Length() < 2 || !info[0].IsNumber() ||
                           !info[1].IsNumber()) {
                         Napi::TypeError::New(env, "Number arguments expected")
                             .ThrowAsJavaScriptException();
                         return env.Null();
                       }
                       int32_t a = info[0].As<Napi::Number>().Int32Value();
                       int32_t b = info[1].As<Napi::Number>().Int32Value();
                       return Napi::Number::New(env,
                                                Calculator::subtract(a, b));
                     }));

  calculator.Set("multiply",
                 Napi::Function::New(
                     env, [](const Napi::CallbackInfo &info) -> Napi::Value {
                       Napi::Env env = info.Env();
                       if (info.Length() < 2 || !info[0].IsNumber() ||
                           !info[1].IsNumber()) {
                         Napi::TypeError::New(env, "Number arguments expected")
                             .ThrowAsJavaScriptException();
                         return env.Null();
                       }
                       int32_t a = info[0].As<Napi::Number>().Int32Value();
                       int32_t b = info[1].As<Napi::Number>().Int32Value();
                       return Napi::Number::New(env,
                                                Calculator::multiply(a, b));
                     }));

  calculator.Set("divide",
                 Napi::Function::New(
                     env, [](const Napi::CallbackInfo &info) -> Napi::Value {
                       Napi::Env env = info.Env();
                       if (info.Length() < 2 || !info[0].IsNumber() ||
                           !info[1].IsNumber()) {
                         Napi::TypeError::New(env, "Number arguments expected")
                             .ThrowAsJavaScriptException();
                         return env.Null();
                       }
                       int32_t a = info[0].As<Napi::Number>().Int32Value();
                       int32_t b = info[1].As<Napi::Number>().Int32Value();
                       auto result = Calculator::divide(a, b);
                       if (result) {
                         return Napi::Number::New(env, *result);
                       } else {
                         Napi::TypeError::New(env, "Division by zero")
                             .ThrowAsJavaScriptException();
                         return env.Null();
                       }
                     }));

  return calculator;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "createCalculator"),
              Napi::Function::New(env, CreateCalculator));
  return exports;
}

NODE_API_MODULE(calculator, Init)
