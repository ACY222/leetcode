// @leet start
impl Solution {
    pub fn maximum_units(box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
        let mut box_types = box_types;
        let mut truck_size = truck_size;
        box_types.sort_unstable_by(|box1, box2| box2[1].cmp(&box1[1]));

        let mut units = 0;
        for box_type in &mut box_types {
            let count = box_type[0];
            let unit = box_type[1];

            if truck_size >= count {
                units += unit * count;
                truck_size -= count;
            } else {
                units += unit * truck_size;
                // truck_size = 0;
                break;
            }
        }

        units
    }
}
// @leet end
