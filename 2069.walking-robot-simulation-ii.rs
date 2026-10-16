// @leet start
enum Dir {
    East,
    West,
    North,
    South,
}
struct Robot {
    width: i32,
    height: i32,
    x: i32,
    y: i32,
    dir: Dir,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */

impl Robot {
    fn new(width: i32, height: i32) -> Self {
        Robot {
            width,
            height,
            x: 0,
            y: 0,
            dir: Dir::East,
        }
    }

    fn step(&mut self, num: i32) {
        let perimeter = 2 * (self.height + self.width - 2);
        let num = num % perimeter;
        match self.dir {
            // 1, 0
            Dir::East => {
                if num > self.width - 1 - self.x {
                    let remaining = num - (self.width - 1 - self.x);
                    self.x = self.width - 1;
                    self.dir = Dir::North;
                    self.step(remaining);
                } else {
                    self.x += num;
                }
            }
            // 0, 1
            Dir::North => {
                if num > self.height - 1 - self.y {
                    let remaining = self.height - 1 - self.y;
                    self.y = self.height - 1;
                    self.dir = Dir::West;
                    self.step(num - remaining);
                } else {
                    self.y += num;
                }
            }
            // -1, 0
            Dir::West => {
                if num > self.x {
                    let remaining = num - self.x;
                    self.x = 0;
                    self.dir = Dir::North;
                    self.step(remaining);
                } else {
                    self.x -= num;
                }
            }
            // 0, -1
            Dir::South => {
                if num > self.y {
                    let remaining = num - self.y;
                    self.y = 0;
                    self.dir = Dir::East;
                    self.step(remaining);
                } else {
                    self.y -= num;
                }
            }
        }
    }

    fn get_pos(&self) -> Vec<i32> {
        vec![self.x, self.y]
    }

    fn get_dir(&self) -> String {
        match self.dir {
            Dir::East => String::from("East"),
            Dir::North => String::from("North"),
            Dir::West => String::from("West"),
            Dir::South => String::from("South"),
        }
    }
}
/**
 * Your Robot object will be instantiated and called as such:
 * let obj = Robot::new(width, height);
 * obj.step(num);
 * let ret_2: Vec<i32> = obj.get_pos();
 * let ret_3: String = obj.get_dir();
 */
// @leet end
