#include "json_read.hpp"
#include <iostream>

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

void create_ball(const rapidjson::Document &json_data) {
  const rapidjson::Value &balls_list = json_data["system"]["balls"];
  assert(balls_list.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = balls_list.Begin();
       itr != balls_list.End(); ++itr) {
    int id = (*itr)["id"].GetInt();
    double mass = (*itr)["mass"].GetDouble();
    double radius = (*itr)["radius"].GetDouble();
    Ball ball(id, ZERO_VEC, ZERO_VEC, mass, radius, sf::Color::White);
       std::cout << "Ball #" << ball.get_id() << ": m = " << ball.get_mass() << ", m_inv = " << ball.get_mass_inv() << ", r = " << ball.get_radius() << std::endl; 
  }
}

// Balls_Vec create_balls_vec(const rapidjson::Document &doc);
