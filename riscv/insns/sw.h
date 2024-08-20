// printf("pc:0x%016lx  store: 0x%016lx \n", STATE.pc , RS1 );
MMU.store<uint32_t>(RS1 + insn.s_imm(), RS2);
