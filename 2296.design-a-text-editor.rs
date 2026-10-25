// @leet start
struct TextEditor {
    left: Vec<char>,
    right: Vec<char>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TextEditor {
    fn new() -> Self {
        TextEditor {
            left: Vec::new(),
            right: Vec::new(),
        }
    }

    fn add_text(&mut self, text: String) {
        for c in text.chars() {
            self.left.push(c);
        }
    }

    fn delete_text(&mut self, k: i32) -> i32 {
        let num_to_delete = self.left.len().min(k as usize);
        self.left.truncate(self.left.len() - num_to_delete);
        num_to_delete as i32
    }

    fn cursor_left(&mut self, k: i32) -> String {
        for _ in 0..k {
            if let Some(c) = self.left.pop() {
                self.right.push(c);
            } else {
                break;
            }
        }

        self.left[self.left.len().saturating_sub(10)..]
            .iter()
            .collect()
    }

    fn cursor_right(&mut self, k: i32) -> String {
        for _ in 0..k {
            if let Some(c) = self.right.pop() {
                self.left.push(c);
            } else {
                break;
            }
        }

        self.left[self.left.len().saturating_sub(10)..]
            .iter()
            .collect()
    }
}
/**
 * Your TextEditor object will be instantiated and called as such:
 * let obj = TextEditor::new();
 * obj.add_text(text);
 * let ret_2: i32 = obj.delete_text(k);
 * let ret_3: String = obj.cursor_left(k);
 * let ret_4: String = obj.cursor_right(k);
 */
// @leet end
