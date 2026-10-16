// @leet start
enum Dir {
    East,
    West,
    North,
    South,
}

struct Robot {
    // width and height have been -= 1
    width: i32,
    height: i32,
    idx: i32,
    dir: Dir,
    is_start_point: bool,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Robot {
    fn new(width: i32, height: i32) -> Self {
        Robot {
            width: width - 1,
            height: height - 1,
            idx: 0,
            dir: Dir::East,
            is_start_point: true,
        }
    }

    fn step(&mut self, num: i32) {
        self.is_start_point = false;
        self.idx += num;
        self.idx %= 2 * (self.width + self.height);
    }

    fn get_pos(&self) -> Vec<i32> {
        return if self.idx <= self.width {
            vec![self.idx, 0]
        } else if self.idx <= self.width + self.height {
            vec![self.width, self.idx - self.width]
        } else if self.idx <= 2 * self.width + self.height {
            vec![2 * self.width + self.height - self.idx, self.height]
        } else {
            vec![0, 2 * (self.width + self.height) - self.idx]
        };
    }

    fn get_dir(&self) -> String {
        if self.idx == 0 {
            return if self.is_start_point {
                String::from("East")
            } else {
                String::from("South")
            };
        }
        return if self.idx <= self.width {
            String::from("East")
        } else if self.idx <= self.width + self.height {
            String::from("North")
        } else if self.idx <= 2 * self.width + self.height {
            String::from("West")
        } else {
            String::from("South")
        };
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
