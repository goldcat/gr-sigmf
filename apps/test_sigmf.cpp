//============================================================================
// Name        : rapidjson_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <sigmf/sigmf_reader.h>
#include <iostream>
#include <cstdio>

int
main ()
{

  std::string file = "/home/ctriant/test2.json";
  gr::sigmf::sigmf_reader reader = gr::sigmf::sigmf_reader(file);

  return 0;
}
