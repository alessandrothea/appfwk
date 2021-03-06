/**
 * @file GraphConstructor.hpp
 *
 * A GraphConstructor defines a DAQ Application's DAQModule graph. It may also
 * register Queues with QueueRegistry.
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef APPFWK_INCLUDE_APPFWK_GRAPHCONSTRUCTOR_HPP_
#define APPFWK_INCLUDE_APPFWK_GRAPHCONSTRUCTOR_HPP_

#include "appfwk/DAQModule.hpp"

#include <list>
#include <map>
#include <memory>
#include <string>

namespace dunedaq::appfwk {
typedef std::map<std::string, std::shared_ptr<DAQModule>> DAQModuleMap; ///< DAQModules indexed by name
typedef std::map<std::string, std::list<std::string>> CommandOrderMap;  ///< Defined DAQModule orders for commands

/**
 * @brief The GraphConstructor class is the representation of a DAQModule and
 * Queue graph
 *
 * The ConstructGraph method is responsible for configuring all Queues and
 * DAQModules for a DAQ Application
 */
class GraphConstructor
{
public:
  /**
   * @brief Construct the DAQModules and retrieve Queue configurations
   * @param[out] daq_module_map A DAQModuleMap that will contain pointers to
   * all of the DAQModule instances, indexed by name
   * @param[out] command_order_map A map relating commands to an ordering of
   * DAQModules (by name)
   *
   * Brief This method is responsible for instantiating and linking all of the
   * Queue and DAQModule instances in a DAQ Application. Additionally, any
   * requirements on command order for DAQModules should be defined here.
   */
  virtual void ConstructGraph(DAQModuleMap& daq_module_map, CommandOrderMap& command_order_map) const = 0;
};
} // namespace dunedaq::appfwk

#endif // APPFWK_INCLUDE_APPFWK_GRAPHCONSTRUCTOR_HPP_
