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
    moved: bool,
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
            moved: false,
        }
    }

    fn step(&mut self, num: i32) {
        self.moved = true;
        self.idx = (self.idx + num) % (2 * (self.width + self.height));
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
        if self.idx == 0 && self.moved {
            return String::from("South");
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
// @leet end
