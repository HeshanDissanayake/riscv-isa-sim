if (sreg_t(RS1) < sreg_t(RS2))
{
  set_pc(BRANCH_TARGET);
  p->get_state()->regsw_enable = 0;
  
}
