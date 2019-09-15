# Driving to Blockchain
This is the smart contract repo for the project "Driving to Blockchain". This smart contract is developed based on PlatON WASM (https://pwasmdoc.platon.network/index.html). Which can be translated to other smart contract language fairly easy.

## physicalDeviceInterface

**This is the gateway bringing physical devices to blockchain smart contract platforms.**

Physical devices, like cars, are already highly informational. We only need

+  An identification held and only held by the car;
+  A smart contract to transfer value and instructions from the information world to the physical world; 
+  And a set of oracles to bridge physical world information to the information world. 

Then, we drive on the blockchain.

### PLATON_ABI(PDI::request, request);
for user/other device sending request to the car

### PLATON_ABI(PDI::prove, prove);
for the car prove its execution

### PLATON_ABI(PDI::message, message);
for oracle inputs

### PLATON_ABI(PDI::cancel, cancel);
for user/other device cancel its request
