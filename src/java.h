#ifndef JAVA_HELPER_H
#define JAVA_HELPER_H

#include <iostream>
#include <vector>
#include <variant>

#include <jni.h>

static int jHelperAlive = 0;

class JavaHelper{
private:
  JavaVM *vm;
  JNIEnv *env;
  JavaVMInitArgs vm_args;

  jclass regexClass;
public:
  JavaHelper();

  std::string regexReplace(std::string string, std::string pattern, std::string replace);


};
#endif   
