Mac:
cmake .. -G "Xcode" -DMNN_METAL=ON -DMNN_DEBUG=ON -DMNN_BUILD_DEMO=ON -DMNN_BUILD_CONVERTER=ON
-f TF --modelFile /Users/Franky/Downloads/freeze_graph.pb --MNNModel /Users/Franky/Downloads/spleeter.mnn --bizCode biz

bazel build -c dbg //tensorflow/core:ops_tests

"configurations": [
{
"name": "(lldb) Launch",
"type": "cppdbg",
"request": "launch",
"program": "${workspaceFolder}/bazel-out/darwin-dbg/bin/tensorflow/core/ops_tests",
"args": [],
"stopAtEntry": false,
"cwd": "${workspaceFolder}",
"environment": [],
"console": "externalTerminal",
"MIMode": "lldb"
}
]