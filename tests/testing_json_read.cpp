#include "json_read.hpp"
#include <rapidjson/document.h>

int main (int argc, char *argv[]) {
  rapidjson::Document json_data = load_json("json/example1.json");
  create_ball(json_data);

  return 0;
}
