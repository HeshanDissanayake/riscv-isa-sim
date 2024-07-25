// See LICENSE for license details.

#include "disasm.h"

const char* xpr_name[] = {
  "zero", "ra", "sp",  "gp",  "tp", "t0",  "t1",  "t2",
  "s0",   "s1", "a0",  "a1",  "a2", "a3",  "a4",  "a5",
  "a6",   "a7", "s2",  "s3",  "s4", "s5",  "s6",  "s7",
  "s8",   "s9", "s10", "s11", "t3", "t4",  "t5",  "t6",

  "n00", "n01", "n02", "n03", "n04", "n05", "n06", "n07",
  "n08", "n09", "n10", "n11", "n12", "n13", "n14", "n15",
  "n16", "n17", "n18", "n19", "n20", "n21", "n22", "n23",
  "n24", "n25", "n26", "n27", "n28", "n29", "n30", "n31",
  
  "n32", "n33", "n34", "n35", "n36", "n37", "n38", "n39",
  "n40", "n41", "n42", "n43", "n44", "n45", "n46", "n47",
  "n48", "n49", "n50", "n51", "n52", "n53", "n54", "n55",
  "n56", "n57", "n58", "n59", "n60", "n61", "n62", "n63",


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
