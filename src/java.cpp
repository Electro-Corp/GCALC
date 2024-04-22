#include "java.h"

JavaHelper::JavaHelper(){
  if(jHelperAlive == 0){
    std::cout << "Init JVM\n";
    vm_args.version = JNI_VERSION_1_2;
    JavaVMOption* options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=../java/";  
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = 1;
    jint res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
  
  
    // Load class
    regexClass = env->FindClass("CalcRegex");
    if(regexClass == nullptr){
      std::cout << "Failed to load class\n";
      exit(-1);
    }
  
    // Confirm that the class was sucessfulyl loaded
    jmethodID mid = env->GetStaticMethodID(regexClass, "confirmAlive", "()V"); 
    if(mid == nullptr){
      std::cout << "Failed to get method ID\n";
      exit(-1);
    }
    env->CallStaticVoidMethod(regexClass, mid);
    jHelperAlive = 1;
  }else{
    std::cout << "JVM Already Init! Do not create two instances of JavaHelper!\n";
    exit(-1);
  }
}


std::string JavaHelper::regexReplace(std::string string, std::string pattern, std::string replace){
  jmethodID mid = env->GetStaticMethodID(regexClass, "replaceAll", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
  if(mid == nullptr){
    std::cout << "Failed to get method ID of replaceAll\n";
    exit(-1);
  }
  
  jstring jString = env->NewStringUTF(string.c_str());
  jstring jPattern = env->NewStringUTF(pattern.c_str());
  jstring jReplace = env->NewStringUTF(replace.c_str());
  
  jobject result = env->CallObjectMethod(jString, mid, jString, jPattern, jReplace);
  const char* str = env->GetStringUTFChars((jstring) result, NULL);
  std::string re(str);
  // Clean up
  env->ReleaseStringUTFChars((jstring)result, str);
  env->DeleteLocalRef(jString);
  env->DeleteLocalRef(jPattern);
  env->DeleteLocalRef(jReplace);
  env->DeleteLocalRef(result);
  return re;
}