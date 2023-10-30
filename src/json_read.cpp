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

Balls_Vec create_balls(const rapidjson::Document &json_data) {
  Balls_Vec balls;
  const rapidjson::Value &balls_list = json_data["system"]["balls"];
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

    // Generate ball
    Ball ball(id, pos, vel, mass, radius, sf::Color::White);
    balls.push_back(ball);
  }
  return balls;
}

// Balls_Vec create_balls_vec(const rapidjson::Document &doc);
