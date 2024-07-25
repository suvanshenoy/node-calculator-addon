
#include "calculator.hpp"
#include <napi.h>

Napi::Object CreateCalculator(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::Object calculator = Napi::Object::New(env);

    auto calc = std::make_shared<Calculator<double>>();

    calculator.Set("add",
                   Napi::Function::New(
                       env,
                       [calc](const Napi::CallbackInfo &info) -> Napi::Value
                       {
                           Napi::Env env = info.Env();
                           if (info.Length() < 2 || !info[0].IsNumber() ||
                               !info[1].IsNumber())
                           {
                               Napi::TypeError::New(env,
                                                    "Number arguments expected")
                                   .ThrowAsJavaScriptException();
                               return env.Null();
                           }
                           double a = info[0].As<Napi::Number>().DoubleValue();
                           double b = info[1].As<Napi::Number>().DoubleValue();
                           return Napi::Number::New(env, calc->add(a, b));
                       }));

    calculator.Set("subtract",
                   Napi::Function::New(
                       env,
                       [calc](const Napi::CallbackInfo &info) -> Napi::Value
                       {
                           Napi::Env env = info.Env();
                           if (info.Length() < 2 || !info[0].IsNumber() ||
                               !info[1].IsNumber())
                           {
                               Napi::TypeError::New(env,
                                                    "Number arguments expected")
                                   .ThrowAsJavaScriptException();
                               return env.Null();
                           }
                           double a = info[0].As<Napi::Number>().DoubleValue();
                           double b = info[1].As<Napi::Number>().DoubleValue();
                           return Napi::Number::New(env, calc->subtract(a, b));
                       }));

    calculator.Set("multiply",
                   Napi::Function::New(
                       env,
                       [calc](const Napi::CallbackInfo &info) -> Napi::Value
                       {
                           Napi::Env env = info.Env();
                           if (info.Length() < 2 || !info[0].IsNumber() ||
                               !info[1].IsNumber())
                           {
                               Napi::TypeError::New(env,
                                                    "Number arguments expected")
                                   .ThrowAsJavaScriptException();
                               return env.Null();
                           }
                           double a = info[0].As<Napi::Number>().DoubleValue();
                           double b = info[1].As<Napi::Number>().DoubleValue();
                           return Napi::Number::New(env, calc->multiply(a, b));
                       }));

    calculator.Set("divide",
                   Napi::Function::New(
                       env,
                       [calc](const Napi::CallbackInfo &info) -> Napi::Value
                       {
                           Napi::Env env = info.Env();
                           if (info.Length() < 2 || !info[0].IsNumber() ||
                               !info[1].IsNumber())
                           {
                               Napi::TypeError::New(env,
                                                    "Number arguments expected")
                                   .ThrowAsJavaScriptException();
                               return env.Null();
                           }
                           double a = info[0].As<Napi::Number>().DoubleValue();
                           double b = info[1].As<Napi::Number>().DoubleValue();
                           auto result = calc->divide(a, b);
                           if (result)
                           {
                               return Napi::Number::New(env, *result);
                           }
                           else
                           {
                               Napi::TypeError::New(env, "Division by zero")
                                   .ThrowAsJavaScriptException();
                               return env.Null();
                           }
                       }));

    return calculator;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "createCalculator"),
                Napi::Function::New(env, CreateCalculator));
    return exports;
}

NODE_API_MODULE(calculator, Init)
