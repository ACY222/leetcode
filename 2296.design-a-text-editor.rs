// @leet start
struct TextEditor {
    left: String,
    right: String,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TextEditor {
    fn new() -> Self {
        TextEditor {
            left: String::new(),
            right: String::new(),
        }
    }

    fn add_text(&mut self, text: String) {
        self.left.push_str(&text);
    }

    fn delete_text(&mut self, k: i32) -> i32 {
        let num_to_delete = self.left.len().min(k as usize);
        self.left.truncate(self.left.len() - num_to_delete);
        num_to_delete as i32
    }

    fn cursor_left(&mut self, k: i32) -> String {
        let k = k as usize;
        for _ in 0..k {
            if let Some(c) = self.left.pop() {
                self.right.push(c);
            } else {
                break;
            }
        }

        self.left[self.left.len().saturating_sub(10)..].to_string()
    }

    fn cursor_right(&mut self, k: i32) -> String {
        let k = k as usize;
        for _ in 0..k {
            if let Some(c) = self.right.pop() {
                self.left.push(c);
            } else {
                break;
            }
        }

        self.left[self.left.len().saturating_sub(10)..].to_string()
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
