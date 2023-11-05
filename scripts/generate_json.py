import json
import numpy as np


def normalize(vec):
    try:
        return vec/np.linalg.norm(vec)
    except ZeroDivisionError:
        raise ValueError(f"Division by zero: {vec}/{np.linalg.norm(vec)}")


class Ball:
    def __init__(self, id, pos, vel, mass, radius, color):
        self.id = id
        self.pos = pos
        self.vel = vel
        self.mass = mass
        self.radius = radius
        self.color = color

    def generate_dict(self):
        return {
            "id": self.id,
            "pos": self.pos.tolist(),
            "vel": self.vel.tolist(),
            "mass": self.mass,
            "radius": self.radius,
            "color": self.color.tolist(),
        }


class Wall:
    def __init__(self, id, p0, normal, color):
        self.id = id
        self.p0 = p0
        self.normal = normalize(normal)
        self.color = color

    def generate_dict(self):
        return {
            "id": self.id,
            "p0": self.p0.tolist(),
            "normal": self.normal.tolist(),
            "color": self.color.tolist(),
        }


class System:
    def __init__(self, size, dt, balls, walls):
        self.width, self.height = np.array(size).astype(float)
        self.dt = dt
        self.balls = balls
        self.walls = walls

    def generate_dict(self):
        return {
            "system": {
                "size": {"width": self.width, "height": self.height},
                "delta_time": self.dt,
                "balls": [ball.generate_dict() for ball in self.balls],
                "walls": [wall.generate_dict() for wall in self.walls],
            }
        }


if __name__ == "__main__":
    ball = Ball(1, np.array([1, -4.5, 100.35]),
                np.zeros(3), 4.5, 20.75, np.array([255, 0, 200]))
    wall = Wall(13, np.array([2.0, -5.0, 1.0]),
                np.array([1.0, -1.0, 2.0]), np.array([0, 0, 255]))
    system = System(np.array([700, 500]), 0.1, [ball], [wall])

    with open("json/from_python_test_1.json", "w") as json_file:
        json.dump(system.generate_dict(), json_file, indent=4)
