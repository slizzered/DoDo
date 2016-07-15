#pragma once

#include <memory>
#include <algorithm>

#include <boost/bimap.hpp>
#include <dodo2/model/worker/Model.hpp>
#include <dodo2/model/hardware/HardwareAbstraction.hpp>
#include <dodo2/model/hardware/HardwareAbstractionBase.hpp>
#include <dodo2/utility/OneToNMap.hpp>


namespace dodo
{
namespace mapping
{
namespace worker2hardware
{


    /**
     * Extensions need to be default-constructible!
     * -> Policy-Based design :)
     */
    template<
        typename T_HardwareAbstraction,
    >
    class Interface
    {
        using HardwareAbstraction = T_HardwareAbstraction;

        using WorkerID = model::worker::Model::WorkerID;
        using HardwareID = HardwareAbstraction::HardwareID;
        std::shared_ptr< model::worker::Model > workerModel;
        std::shared_ptr< HardwareAbstraction > hardwareModel;
        utility::OneToNMap<HardwareID, WorkerID> mapping;

    public:

        Interface(
            const std::shared_ptr< model::worker::Model > & workerModel,
            const std::shared_ptr< HardwareAbstraction > & hardwareModel
        ) :
            workerModel( workerModel ),
            hardwareModel( hardwareModel )
        { }

        Interface(
            const std::shared_ptr< model::worker::Model > & workerModel,
            const std::shared_ptr< HardwareAbstraction > & hardwareModel,
            const std::map<
                WorkerID,
                HardwareID
            > & worker2hw
        ) :
            workerModel( workerModel ),
            hardwareModel( hardwareModel ),
            mapping(worker2hw)
        { }

        Interface(
            const std::shared_ptr< model::worker::Model > & workerModel,
            const std::shared_ptr< HardwareAbstraction > & hardwareModel,
            const std::map<
                HardwareID,
                std::vector< WorkerID >
            > & hw2worker
        ) :
            workerModel( workerModel ),
            hardwareModel( hardwareModel ),
            mapping(hw2worker)
        { }

        auto
        moveWorkerToCore(
            const WorkerID w,
            const HardwareID& h
        )
        {
            mapping.eraseMapping(w);
            mapping.addMapping(h, w);
        }

        auto
        getWorkersOfCore( const HardwareID& h )
        {
            return mapping.one2n[h];
        }

        auto
        getHWOfWorker( const WorkerID w )
        {
            return mapping.n2one.at(w);
        }

    };

} /* worker2hardware */
} /* mapping */
} /* dodo */
