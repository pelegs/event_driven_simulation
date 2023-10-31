#include "balls.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "system.hpp"
#include "walls.hpp"
#include "maths.hpp"
#include "graphics.hpp"

#include <string>

rapidjson::Document load_json(const char *filename);

Balls_Vec create_balls(const rapidjson::Document &balls_data);
Walls_Vec create_walls(const rapidjson::Document &walls_data);
