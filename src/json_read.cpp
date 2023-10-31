#include "json_read.hpp"
#include <iostream>
#include <rapidjson/document.h>

rapidjson::Document load_json(const char *filename) {
  // NOTE: This MUST be refurbished with try/catch!
  FILE *fp = fopen(filename, "r");
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document doc;
  doc.ParseStream(is);
  fclose(fp);
  return doc;
}

Balls_Vec create_balls(const rapidjson::Document &balls_data) {
  Balls_Vec balls;
  const rapidjson::Value &balls_list = balls_data["system"]["balls"];
  assert(balls_list.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = balls_list.Begin();
       itr != balls_list.End(); ++itr) {
    // Single-valued parameters
    int id = (*itr)["id"].GetInt();
    double mass = (*itr)["mass"].GetDouble();
    double radius = (*itr)["radius"].GetDouble();

    // Position
    vec pos;
    const rapidjson::Value &pos_arr = (*itr)["pos"];
    assert(pos_arr.IsArray());
    pos.x = pos_arr[0].GetDouble();
    pos.y = pos_arr[1].GetDouble();
    // pos.z = pos_arr[2].GetDouble();

    // Velocity
    vec vel;
    const rapidjson::Value &vel_arr = (*itr)["vel"];
    assert(vel_arr.IsArray());
    vel.x = vel_arr[0].GetDouble();
    vel.y = vel_arr[1].GetDouble();
    // vel.z = vel_arr[2].GetDouble();

    // Color
    sf::Color color;
    const rapidjson::Value &color_arr = (*itr)["color"];
    assert(color_arr.IsArray());
    color.r = color_arr[0].GetInt();
    color.g = color_arr[1].GetInt();
    color.b = color_arr[2].GetInt();

    // Generate ball
    Ball ball(id, pos, vel, mass, radius, color);
    balls.push_back(ball);
  }
  return balls;
}

Walls_Vec create_walls(const rapidjson::Document &walls_data) {
  Walls_Vec walls;
  const rapidjson::Value &walls_list = walls_data["system"]["walls"];
  assert(walls_list.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = walls_list.Begin();
       itr != walls_list.End(); ++itr) {
    // Single-valued parameter
    int id = (*itr)["id"].GetInt();

    // p0
    vec p0;
    const rapidjson::Value &p0_arr = (*itr)["p0"];
    assert(p0_arr.IsArray());
    p0.x = p0_arr[0].GetDouble();
    p0.y = p0_arr[1].GetDouble();
    // pos.z = pos_arr[2].GetDouble();

    // Normal
    vec normal;
    const rapidjson::Value &normal_arr = (*itr)["normal"];
    assert(normal_arr.IsArray());
    normal.x = normal_arr[0].GetDouble();
    normal.y = normal_arr[1].GetDouble();
    // pos.z = pos_arr[2].GetDouble();

    // Color
    sf::Color color;
    const rapidjson::Value &color_arr = (*itr)["color"];
    assert(color_arr.IsArray());
    color.r = color_arr[0].GetInt();
    color.g = color_arr[1].GetInt();
    color.b = color_arr[2].GetInt();

    // Generate wall
    Wall wall(id, p0, normal, color);
    walls.push_back(wall);
  }
  return walls;
}
