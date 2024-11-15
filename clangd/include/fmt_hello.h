#pragma once
#include "fmt/format.h"
#include "glm/common.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/glm.hpp"
#include <iostream>
static void fmt_hello() { fmt::print("hello\n"); }

static glm::vec3 glm_test() {
  glm::vec3 testvect1(1.0, 2.0, 3.0);
  glm::vec3 testvect2(0.0, 2.0, 1.0);
  return testvect1 + testvect2;
}
