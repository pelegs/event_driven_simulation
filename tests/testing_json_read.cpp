#include "json_read.hpp"
#include <rapidjson/document.h>

int main(int argc, char *argv[]) {
  rapidjson::Document json_data = load_json("json/example1.json");
  Balls_Vec balls = create_balls(json_data);
  for (auto ball : balls)
    ball.get_data();
  Walls_Vec walls = create_walls(json_data);
  for (auto wall : walls)
    wall.get_data();

  return 0;
}
