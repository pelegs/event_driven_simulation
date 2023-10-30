#include "balls.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "system.hpp"
#include "walls.hpp"
#include "maths.hpp"
#include "graphics.hpp"

#include <string>

rapidjson::Document load_json(const char *filename);

void create_ball(const rapidjson::Document &json_data);
Balls_Vec create_balls_vec(const rapidjson::Document &doc);
