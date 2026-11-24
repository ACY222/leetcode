// @leet start
use std::collections::HashMap;

struct TimeMap {
    map: HashMap<String, String>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {
    fn new() -> Self {
        Self {
            map: HashMap::new(),
        }
    }

    fn set(&mut self, key: String, value: String, _timestamp: i32) {
        self.map.insert(key, value);
    }

    fn get(&self, key: String, _timestamp: i32) -> String {
        self.map
            .get(&key)
            .cloned()
            .unwrap_or_else(|| String::from(""))
    }
}
/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
// @leet end
