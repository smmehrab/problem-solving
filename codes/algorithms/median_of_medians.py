class MedianFinder:

    def __init__(self):
        pass

    def partition(self, data, partition_size):
        # print("Inside Partition")
        return [data[i:(i+partition_size)] for i in range(0, len(data), partition_size)]

    def pivot_selector(self, data):
        """
          finds the optimal pivot
          using 5 element partitions
        """

        # print("Inside Pivot Selector")
        partition_size = 5

        data_size = len(data)
        assert data_size > 0

        if data_size < partition_size:
            return sorted(data)[data_size//2]

        chunks = self.partition(data, partition_size)
        full_chunks = [chunk for chunk in chunks if len(chunk) == 5]
        sorted_chunks = [sorted(chunk) for chunk in full_chunks]
        chunks_medians = [chunk[2] for chunk in sorted_chunks]

        median_of_medians = self.find(chunks_medians)
        return median_of_medians

    def quickselect(self, data, k):
        """
            recursively searching for the median
        """

        # print("Inside QuickSelect")
        if len(data) == 1:
            assert k == 0
            return data[0]

        pivot = self.pivot_selector(data)

        left = [i for i in data if i < pivot]
        right = [i for i in data if i > pivot]
        pivots = [i for i in data if i == pivot]

        # kth element in left subarray
        if k < len(left):
            return self.quickselect(left, k)

        # kth element == pivot
        elif k < (len(left) + len(pivots)):
            return pivot

        # kth element in right subarray
        else:
            new_k = k - len(left) - len(pivots)
            return self.quickselect(right, new_k)

    def find(self, data):
      """
        finds median in linear time
        O(n)
      """

      # print("Inside Find")
      data_size = len(data)

      if(data_size<5):
          data.sort()
          if (data_size&1) == 1:
              m = data[(data_size//2)]
              return m
          else:
              m1 = data[(data_size//2)-1]
              m2 = data[(data_size//2)]
              return (0.5) * (m1+m2)
      
      # odd length data
      if (data_size & 1) == 1:
          m = self.quickselect(data, (data_size//2))
          return m

      # even length data
      else:
          m1 = self.quickselect(data, ((data_size/2)-1))
          m2 = self.quickselect(data, (data_size/2))
          return (0.5) * (m1+m2)
