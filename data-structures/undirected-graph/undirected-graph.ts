type NodeName = string;

const createUndirectedGraph = () => {
  const graph = new Map();

  const addNode = (name: NodeName, value: unknown) => {
    graph.set(name, { value, adjacents: [] });
  };

  const addEdge = (node1: NodeName, node2: NodeName) => {
    if (!graph.has(node1)) throw new Error("Node 1 doesn't exists!");
    if (!graph.has(node2)) throw new Error("Node 2 doesn't exists!");

    const node1Data = graph.get(node1);
    const node2Data = graph.get(node2);

    if (node1Data.adjacents.includes(node2)) return;

    graph.set(node1, {
      ...node1Data,
      adjacents: [...node1Data.adjacents, node2],
    });

    graph.set(node2, {
      ...node2Data,
      adjacents: [...node2Data.adjacents, node1],
    });
  };

  const removeEdge = (node1: NodeName, node2: NodeName) => {
    if (!graph.has(node1)) throw new Error("Node 1 doesn't exists!");
    if (!graph.has(node2)) throw new Error("Node 2 doesn't exists!");

    const node1Data = graph.get(node1);
    const node2Data = graph.get(node2);

    graph.set(node1, {
      ...node1Data,
      adjacents: node1Data.adjacents.filter((x) => x !== node2),
    });

    graph.set(node2, {
      ...node2Data,
      adjacents: node2Data.adjacents.filter((x) => x !== node1),
    });
  };

  const removeNode = (node: NodeName) => {
    if (!graph.has(node)) return;
    graph.get(node).adjacents.forEach((x) => {
      const currentNodeData = graph.get(x);
      graph.set(x, {
        ...currentNodeData,
        adjacents: currentNodeData.adjacents.filter((item) => item !== node),
      });
    });
    graph.delete(node);
  };

  return {
    addNode,
    removeNode,
    addEdge,
    removeEdge,
    getGraph: () => Object.fromEntries(graph),
  };
};

const { addNode, removeNode, addEdge, removeEdge, getGraph } =
  createUndirectedGraph();

console.log(getGraph());

addNode("tom", { name: "tom" });
addNode("sarah", { name: "sarah" });
addNode("alexander", { name: "sarah" });

addEdge("tom", "sarah");
addEdge("tom", "alexander");

console.log(getGraph());

removeEdge("tom", "sarah");

console.log(getGraph());

removeNode("alexander");

console.log(getGraph());
