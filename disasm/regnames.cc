// See LICENSE for license details.

#include "disasm.h"

const char* xpr_name[] = {
  "zero", "ra", "sp",  "gp",  "tp", "t0",  "t1",  "t2",
  "s0",   "s1", "a0",  "a1",  "a2", "a3",  "a4",  "a5",
  "a6",   "a7", "s2",  "s3",  "s4", "s5",  "s6",  "s7",
  "s8",   "s9", "s10", "s11", "t3", "t4",  "t5",  "t6",

  "b1_0"  , "b1_n1" , "b1_n2" , "b1_n3" , "b1_n4" , "b1_n5" , "b1_n6" , "b1_n7",
  "b1_n8" , "b1_n9" , "b1_n10", "b1_n11", "b1_n12", "b1_n13", "b1_n14", "b1_n15",
  "b1_n16", "b1_n17", "b1_n18", "b1_n19", "b1_n20", "b1_n21", "b1_n22", "b1_n23",
  "b1_n24", "b1_n25", "b1_n26", "b1_n27", "b1_n28", "b1_n29", "b1_n30", "b1_n31",

  "b2_0"  , "b2_n1" , "b2_n2" , "b2_n3" , "b2_n4" , "b2_n5" , "b2_n6" , "b2_n7",
  "b2_n8" , "b2_n9" , "b2_n10", "b2_n11", "b2_n12", "b2_n13", "b2_n14", "b2_n15",
  "b2_n16", "b2_n17", "b2_n18", "b2_n19", "b2_n20", "b2_n21", "b2_n22", "b2_n23",
  "b2_n24", "b2_n25", "b2_n26", "b2_n27", "b2_n28", "b2_n29", "b2_n30", "b2_n31",

};

const char* fpr_name[] = {
  "ft0", "ft1", "ft2",  "ft3",  "ft4", "ft5", "ft6",  "ft7",
  "fs0", "fs1", "fa0",  "fa1",  "fa2", "fa3", "fa4",  "fa5",
  "fa6", "fa7", "fs2",  "fs3",  "fs4", "fs5", "fs6",  "fs7",
  "fs8", "fs9", "fs10", "fs11", "ft8", "ft9", "ft10", "ft11"
};

const char* vr_name[] = {
  "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",
  "v8",  "v9",  "v10", "v11", "v12", "v13", "v14", "v15",
  "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23",
  "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"
};

const char* csr_name(int which) {
  switch (which) {
    #define DECLARE_CSR(name, number)  case number: return #name;
    #include "encoding.h"
    #undef DECLARE_CSR
  }
  return "unknown-csr";
}
