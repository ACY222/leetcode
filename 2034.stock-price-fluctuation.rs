// @leet start
use std::collections::{BTreeMap, HashMap};
struct StockPrice {
    time_to_price: HashMap<i32, i32>,
    price_to_count: BTreeMap<i32, i32>,
    curr_time: i32,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockPrice {
    fn new() -> Self {
        StockPrice {
            time_to_price: HashMap::new(),
            price_to_count: BTreeMap::new(),
            curr_time: 0,
        }
    }

    fn update(&mut self, timestamp: i32, price: i32) {
        // handle with old entry
        if self.time_to_price.contains_key(&timestamp) {
            let old_price = self.time_to_price.get(&timestamp).unwrap();
            if self.price_to_count.get(old_price) == Some(&1) {
                self.price_to_count.remove(old_price);
            } else {
                *self.price_to_count.get_mut(old_price).unwrap() -= 1;
            }
        }
        self.time_to_price.insert(timestamp, price);
        if timestamp > self.curr_time {
            self.curr_time = timestamp;
        }

        *self.price_to_count.entry(price).or_insert(0) += 1;
    }

    fn current(&self) -> i32 {
        self.time_to_price[&self.curr_time]
    }

    fn maximum(&self) -> i32 {
        *self.price_to_count.last_key_value().unwrap().0
    }

    fn minimum(&self) -> i32 {
        *self.price_to_count.first_key_value().unwrap().0
    }
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * let obj = StockPrice::new();
 * obj.update(timestamp, price);
 * let ret_2: i32 = obj.current();
 * let ret_3: i32 = obj.maximum();
 * let ret_4: i32 = obj.minimum();
 */
// @leet end
