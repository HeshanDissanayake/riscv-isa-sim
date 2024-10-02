if(STATE.locked == 1){
  // printf("RS1: 0x%016lx RS2: 0x%016lx \n", sreg_t(RS1), sreg_t(RS2));
}

if (sreg_t(RS1) < sreg_t(RS2))
{
  set_pc(BRANCH_TARGET);
  if(STATE.locked == 1){
    // printf("branched\n");
  }
}