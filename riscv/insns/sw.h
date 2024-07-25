// printf("n12:0x%016lx rs2:%ld im:%ld \n",READ_REG(45), RS2, insn.s_imm());
MMU.store<uint32_t>(RS1 + insn.s_imm(), RS2);
