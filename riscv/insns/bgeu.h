if (RS1 >= RS2){
  set_pc(BRANCH_TARGET);
  p->get_state()->regsw_enable = 0;
}
