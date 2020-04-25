// k2/csrc/fsa_algo_test.cc

// Copyright (c)  2020  Fangjun Kuang (csukuangfj@gmail.com)

// See ../../LICENSE for clarification regarding multiple authors

#include "k2/csrc/fsa_algo.h"

#include <utility>
#include <vector>

#include "gtest/gtest.h"
#include "k2/csrc/fsa_renderer.h"

namespace k2 {

TEST(FsaAlgo, Connect) {
  std::vector<Arc> arcs = {
      {0, 1, 1}, {0, 2, 2}, {1, 3, 3}, {1, 6, 6},
      {2, 4, 2}, {2, 6, 3}, {5, 0, 1},
  };

  std::vector<int32_t> arc_indexes = {0, 2, 4, 6, 6, 6, 7};

  Fsa fsa;
  fsa.arc_indexes = std::move(arc_indexes);
  fsa.arcs = std::move(arcs);

  ConnectCore(fsa, nullptr);

  // for debug only
  FsaRenderer renderer(fsa);
  std::cerr << renderer.Render();
}

}  // namespace k2
