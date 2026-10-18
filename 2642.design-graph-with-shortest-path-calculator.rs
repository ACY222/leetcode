// @leet start
use std::cmp::Ordering;
use std::collections::BinaryHeap;

struct Node {
    edges: Vec<Edge>,
}

struct Edge {
    to: usize,
    weight: i32,
}

struct Graph {
    nodes: Vec<Node>,
}

#[derive(PartialEq, Eq)]
struct State {
    id: usize,
    cost: i32,
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.id.cmp(&other.id))
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Graph {
    fn new(n: i32, edges: Vec<Vec<i32>>) -> Self {
        let mut graph = Graph {
            nodes: Vec::with_capacity(n as usize),
        };

        for id in 0..n {
            graph.nodes.push(Node { edges: Vec::new() });
        }

        for edge in edges {
            let from = edge[0] as usize;
            let to = edge[1];
            let weight = edge[2];

            graph.nodes[from].edges.push(Edge {
                to: to as usize,
                weight,
            });
        }

        graph
    }

    fn add_edge(&mut self, edge: Vec<i32>) {
        let from = edge[0] as usize;
        let to = edge[1];
        let weight = edge[2];

        self.nodes[from].edges.push(Edge {
            to: to as usize,
            weight,
        });
    }

    fn shortest_path(&self, node1: i32, node2: i32) -> i32 {
        let mut dist = vec![i32::MAX; self.nodes.len()];
        let mut heap = BinaryHeap::new();

        let node1 = node1 as usize;
        dist[node1] = 0;
        heap.push(State { id: node1, cost: 0 });

        while let Some(State { id: curr, cost }) = heap.pop() {
            if cost > dist[curr] {
                continue;
            }

            if curr == node2 as usize {
                return dist[curr];
            }

            for edge in &self.nodes[curr].edges {
                let Edge { to: next, weight } = edge;
                let next = *next as usize;

                if dist[next] > dist[curr] + weight {
                    dist[next] = dist[curr] + weight;
                    heap.push(State {
                        id: next,
                        cost: dist[next],
                    });
                }
            }
        }

        -1
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * let obj = Graph::new(n, edges);
 * obj.add_edge(edge);
 * let ret_2: i32 = obj.shortest_path(node1, node2);
 */
// @leet end
