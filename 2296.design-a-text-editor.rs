// @leet start
struct TextEditor {
    text: String,
    cursor_pos: usize,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TextEditor {

    fn new() -> Self {
        TextEditor { text: String::new(), cursor_pos: 0 }
    }

    fn add_text(&mut self, text: String) {
        self.text.insert_str(self.cursor_pos, &text);
        self.cursor_pos += text.len();
    }

    fn delete_text(&mut self, k: i32) -> i32 {
        let num_to_delete = self.cursor_pos.min(k as usize);
        self.text.drain(self.cursor_pos - num_to_delete..self.cursor_pos);
        self.cursor_pos -= num_to_delete;
        num_to_delete as i32
    }

    fn cursor_left(&mut self, k: i32) -> String {
        let k = self.cursor_pos.min(k as usize);
        self.cursor_pos -=  k;
        let len_to_return = self.cursor_pos.min(10);
        self.text[self.cursor_pos - len_to_return..self.cursor_pos].to_string()
    }

    fn cursor_right(&mut self, k: i32) -> String {
        let k = (self.text.len() - self.cursor_pos).min(k as usize);
        self.cursor_pos += k;
        let len_to_return = self.cursor_pos.min(10);
        self.text[self.cursor_pos - len_to_return..self.cursor_pos].to_string()
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
