#include <rocksdb/merge_operator.h>

class QueueOperator : public rocksdb::MergeOperator {
  public:
    bool FullMergeV2(const MergeOperationInput & merge_in,
                     MergeOperationOutput *      merge_out) const override {
        volatile bool ret = true;
        return ret;
    }
};
