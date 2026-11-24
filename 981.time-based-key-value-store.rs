// @leet start
use std::collections::HashMap;

struct TimeMap {
    map: HashMap<String, Vec<(i32, String)>>,
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

    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.map
            .entry(key)
            .or_insert_with(|| Vec::new())
            .push((timestamp, value));
    }

    fn get(&self, key: String, timestamp: i32) -> String {
        if !self.map.contains_key(&key) {
            return "".to_string();
        }

        let vec = self.map.get(&key).unwrap();
        let p = vec.partition_point(|item| item.0 <= timestamp);
        if p == 0 {
            "".to_string()
        } else {
            vec[p - 1].1.clone()
        }
    }
}
/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
// @leet end
