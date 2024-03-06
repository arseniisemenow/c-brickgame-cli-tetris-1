#include "block.h"

#include <stdlib.h>

BlockType GetRandomBlockType() {
  BlockType block_type = rand() % (kBlockZ + 1);
  return block_type;
}

BlockRotation GetNextBlockRotation(BlockRotation block_rotation) {
  BlockRotation next_block_rotation = kBlockRotationFirst;
  if (block_rotation == kBlockRotationFirst) {
    next_block_rotation = kBlockRotationSecond;
  } else if (block_rotation == kBlockRotationSecond) {
    next_block_rotation = kBlockRotationThird;
  } else if (block_rotation == kBlockRotationThird) {
    next_block_rotation = kBlockRotationForth;
  } else if (block_rotation == kBlockRotationForth) {
    next_block_rotation = kBlockRotationFirst;
  }
  return next_block_rotation;
}

BlockRotation GetPreviousBlockRotation(BlockRotation block_rotation) {
  BlockRotation previous_block_rotation = kBlockRotationFirst;
  if (block_rotation == kBlockRotationFirst) {
    previous_block_rotation = kBlockRotationForth;
  } else if (block_rotation == kBlockRotationSecond) {
    previous_block_rotation = kBlockRotationFirst;
  } else if (block_rotation == kBlockRotationThird) {
    previous_block_rotation = kBlockRotationSecond;
  } else if (block_rotation == kBlockRotationForth) {
    previous_block_rotation = kBlockRotationThird;
  }
  return previous_block_rotation;
}

BlockColorType GetBlockColor(BlockType block_type) {
  BlockColorType block_color_type = {0};
  block_color_type = kBlockColors[block_type];
  return block_color_type;
}