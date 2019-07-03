#ifndef MELLOCOLATE_XVIZ_BUILDER_H_
#define MELLOCOLATE_XVIZ_BUILDER_H_

#include "connector/xviz/xviz_pose_builder.h"
#include "connector/xviz/xviz_primitive_builder.h"
#include "connector/xviz/xviz_time_series_builder.h"

#include <boost/optional.hpp>

#include <vector>


namespace mellocolate {

class XVIZBuilder {
public:
  XVIZBuilder() = default;

  XVIZBuilder& AddTimestamp(double timestamp);
  XVIZBuilder& AddPose(XVIZPoseBuilder pose);
  XVIZBuilder& AddPrimitive(XVIZPrimitiveBuider primitive);
  XVIZBuilder& AddTimeSeries(XVIZTimeSeriesBuider time_series);

  std::string GetData() const;
private:
  boost::optional<double> timestamp_ = boost::none;
  std::vector<XVIZPoseBuilder> poses_;
  std::vector<XVIZPrimitiveBuider> primitives_;
  std::vector<XVIZTimeSeriesBuider> time_series_;

};
} // namespace mellocolate



#endif