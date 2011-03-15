// Copyright 2011 the V8 project authors. All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Google Inc. nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef V8_MIPS_LITHIUM_MIPS_H_
#define V8_MIPS_LITHIUM_MIPS_H_

#include "hydrogen.h"
#include "lithium-allocator.h"
#include "lithium.h"
#include "safepoint-table.h"

// Note: this file was taken from the X64 version. ARM has a partially working
// lithium implementation, but for now it is not ported to mips.

namespace v8 {
namespace internal {

// Forward declarations.
class LCodeGen;
class LEnvironment;
class Translation;

class LInstruction: public ZoneObject {
 public:
  LInstruction() { }
  virtual ~LInstruction() { }

  // Predicates should be generated by macro as in lithium-ia32.h.
  virtual bool IsLabel() const {
    UNIMPLEMENTED();
    return false;
  }
  virtual bool IsOsrEntry() const {
    UNIMPLEMENTED();
    return false;
  }

  LPointerMap* pointer_map() const {
    UNIMPLEMENTED();
    return NULL;
  }

  bool HasPointerMap() const {
    UNIMPLEMENTED();
    return false;
  }

  virtual void PrintTo(StringStream* stream) const { UNIMPLEMENTED(); }

  virtual bool IsControl() const {
    UNIMPLEMENTED();
    return false;
  }
};


class LGap: public LInstruction {
 public:
  explicit LGap(HBasicBlock* block) { }

  HBasicBlock* block() const {
    UNIMPLEMENTED();
    return NULL;
  }

  enum InnerPosition {
    BEFORE,
    START,
    END,
    AFTER,
    FIRST_INNER_POSITION = BEFORE,
    LAST_INNER_POSITION = AFTER
  };

  LParallelMove* GetOrCreateParallelMove(InnerPosition pos) {
    UNIMPLEMENTED();
    return NULL;
  }

  LParallelMove* GetParallelMove(InnerPosition pos)  {
    UNIMPLEMENTED();
    return NULL;
  }
};


class LLabel: public LGap {
 public:
  explicit LLabel(HBasicBlock* block) : LGap(block) { }
};


class LOsrEntry: public LInstruction {
 public:
  // Function could be generated by a macro as in lithium-ia32.h.
  static LOsrEntry* cast(LInstruction* instr) {
    UNIMPLEMENTED();
    return NULL;
  }

  LOperand** SpilledRegisterArray() {
    UNIMPLEMENTED();
    return NULL;
  }
  LOperand** SpilledDoubleRegisterArray() {
    UNIMPLEMENTED();
    return NULL;
  }

  void MarkSpilledRegister(int allocation_index, LOperand* spill_operand) {
    UNIMPLEMENTED();
  }
  void MarkSpilledDoubleRegister(int allocation_index,
                                 LOperand* spill_operand) {
    UNIMPLEMENTED();
  }
};


class LChunk: public ZoneObject {
 public:
  explicit LChunk(HGraph* graph) { }

  HGraph* graph() const {
    UNIMPLEMENTED();
    return NULL;
  }

  const ZoneList<LPointerMap*>* pointer_maps() const {
    UNIMPLEMENTED();
    return NULL;
  }

  LOperand* GetNextSpillSlot(bool double_slot) {
    UNIMPLEMENTED();
    return NULL;
  }

  LConstantOperand* DefineConstantOperand(HConstant* constant) {
    UNIMPLEMENTED();
    return NULL;
  }

  LLabel* GetLabel(int block_id) const {
    UNIMPLEMENTED();
    return NULL;
  }

  const ZoneList<LInstruction*>* instructions() const {
    UNIMPLEMENTED();
    return NULL;
  }

  int GetParameterStackSlot(int index) const {
    UNIMPLEMENTED();
    return 0;
  }

  void AddGapMove(int index, LOperand* from, LOperand* to) { UNIMPLEMENTED(); }

  LGap* GetGapAt(int index) const {
    UNIMPLEMENTED();
    return NULL;
  }

  bool IsGapAt(int index) const {
    UNIMPLEMENTED();
    return false;
  }

  int NearestGapPos(int index) const {
    UNIMPLEMENTED();
    return 0;
  }

  void MarkEmptyBlocks() { UNIMPLEMENTED(); }

#ifdef DEBUG
  void Verify() { UNIMPLEMENTED(); }
#endif
};


class LChunkBuilder BASE_EMBEDDED {
 public:
  LChunkBuilder(HGraph* graph, LAllocator* allocator) { }

  // Build the sequence for the graph.
  LChunk* Build() {
    UNIMPLEMENTED();
    return NULL;
  };

  // Declare methods that deal with the individual node types.
#define DECLARE_DO(type) LInstruction* Do##type(H##type* node) { \
    UNIMPLEMENTED(); \
    return NULL; \
  }
  HYDROGEN_CONCRETE_INSTRUCTION_LIST(DECLARE_DO)
#undef DECLARE_DO

  DISALLOW_COPY_AND_ASSIGN(LChunkBuilder);
};


} }  // namespace v8::internal

#endif  // V8_MIPS_LITHIUM_MIPS_H_
