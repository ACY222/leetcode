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
    step: i32,
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
            step: 0,
        }
    }

    fn step(&mut self, num: i32) {
        self.step += num;
    }

    fn get_pos(&self) -> Vec<i32> {
        let (x, y, _) = Self::map(&self);
        vec![x, y]
    }

    fn get_dir(&self) -> String {
        let (x, y, dir) = Self::map(&self);
        return String::from(if x + y == 0 && self.step != 0 {
            "South"
        } else {
            dir
        });
    }

    fn map(&self) -> (i32, i32, &str) {
        let perimeter = 2 * (self.width + self.height);
        let step = self.step % perimeter;

        match step {
            s if s <= self.width => (s, 0, "East"),
            s if s <= self.width + self.height => (self.width, s - self.width, "North"),
            s if s <= 2 * self.width + self.height => {
                (2 * self.width + self.height - s, self.height, "West")
            }
            s => (0, perimeter - s, "South"),
        }
    }
}
// @leet end
