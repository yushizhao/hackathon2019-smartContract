# Driving to Blockchain
This is the smart contract repo for the project "Driving to Blockchain". This smart contract is developed based on PlatON WASM (https://pwasmdoc.platon.network/index.html). Which can be translated to other smart contract language fairly easy.

## physicalDeviceInterface

**This is the gateway bringing physical device to blockchain smart contract platform.**

Physical device, like a car is already highly informational. 

### PLATON_ABI(PDI::request, request);
for user/other device sending request to the car

### PLATON_ABI(PDI::prove, prove);
for the car prove its execution

### PLATON_ABI(PDI::message, message);
for oracle inputs

### PLATON_ABI(PDI::cancel, cancel);
for user/other device cancel its request