```
mermaid
flowchart TD
    Title["Flowchart 1: Dijkstra's Algorithm (Basic)"]
    A([Start]) --> B[/"Input number of routers<br>and communication links"/]
    B --> C["Create graph using<br>adjacency list"]
    C --> D[/"Input source and destination<br>routers with link costs"/]
    D --> E["Initialize distances (0 for source,<br>∞ for others) and parent array"]
    E --> F["Apply Dijkstra's algorithm<br>to find minimum distances"]
    F --> G[/"Display minimum link costs<br>from source router"/]
    G --> H[/"Input destination router"/]
    H --> I["Reconstruct and display<br>complete shortest path<br>and total cost"]
    I --> J([Stop])
    Title --> A
    %% Styles - same colors as your image
    classDef titleStyle fill:#D6E4FF,stroke:#333,stroke-width:2px
    classDef startStop fill:#FFB6C1,stroke:#333,stroke-width:1.5px
    classDef input fill:#D8CFF8,stroke:#333,stroke-width:1.5px
    classDef processGreen fill:#C8F0C8,stroke:#333,stroke-width:1.5px
    classDef processBlue fill:#C2DFFF,stroke:#333,stroke-width:1.5px
    classDef processYellow fill:#FFF2A8,stroke:#333,stroke-width:1.5px
    class Title titleStyle
    class A,J startStop
    class B,D,G,H input
    class C,I processGreen
    class E processBlue
    class F processYellow
```
 
