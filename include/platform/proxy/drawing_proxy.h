/*
 * File: drawing_proxy.h
 * Author: Minjun Xu (mjxu96@gmail.com)
 * File Created: Monday, 7th October 2019 5:54:33 pm
 */

#ifndef MELLOCOLATE_DRAWING_PROXY_H_
#define MELLOCOLATE_DRAWING_PROXY_H_

#include "platform/utils/def.h"
#include "platform/utils/json.hpp"
#include "platform/utils/macrologger.h"

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>

namespace mellocolate {

class DrawingProxy {
 public:
  DrawingProxy(uint16_t listen_port);
  std::vector<std::pair<uint32_t, std::vector<point_3d_t>>> GetPolyLines();
  void StartListen();

 private:
  uint16_t listen_port_{8089u};
  void Accept();
  void AddClient(
      boost::asio::basic_stream_socket<boost::asio::ip::tcp>& socket);

  std::vector<point_3d_t> DecodeToPoints(const std::string& str);

  std::mutex polyline_update_lock_{};
  std::unordered_map<uint32_t, std::vector<point_3d_t>> polylines_{};

  std::mutex add_client_lock_{};
  uint32_t client_max_id_{0u};
};

}  // namespace mellocolate

#endif