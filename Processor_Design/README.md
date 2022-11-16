## Processor Design

The current objective is to design the datapath for a multi cycle processor. The processor will have the following components.
- [x] 32-bit alu
- [x] Register File containing 32 registers with 32 bit width having 2 read ports and 1 write port.
- [ ] Instruction Memory
- [ ] Data Memory
- [ ] Steering logic (Conataining the multiplexors, demultiplexors and splitters)
- [ ] Control unit for getting inputs for the steering logic
- [ ] Program Counter (Partly Done)

As of now we will prepare designs for few of these components assuming a single cycle processor and later incorporate the extra components required for the multi-cycle component and finish off the design.

## Version Info

* v1.0 - Single Cycle CPU with limited instruction compatibility as defined in checkpoint 2
* v1.1 - Reorganized and cleanup of v1.0 directory 
* v1.2 - **(Not Done)** Design fixes and improved immediate generation component of v1.1