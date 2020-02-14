//
// Created by 毛华伟 on 2020/1/16.
//

#include "NetWorkManager.h"
#include <rxcpp/operators/rx-observe_on.hpp>
#include <rxcpp/operators/rx-subscribe_on.hpp>
#include <QThread>
#include <QDebug>


rxqt::run_loop *NetWorkManager::m_rxqt_run_loop = nullptr;


void NetWorkManager::init(rxqt::run_loop &rxqt_run_loop)
{
    m_rxqt_run_loop = &rxqt_run_loop;
}

void NetWorkManager::applogin(LoginQuickView *view)
{
    
    //rxqt::run_loop rxqt_run_loop;
    auto main_thread = m_rxqt_run_loop->observe_on_run_loop();
    rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> subscriber)
                                     {
                                         for (int i = 0; i < 100; i++)
                                         {
                                             std::cout << " ob : " << std::this_thread::get_id() << std::endl;
                                             subscriber.on_next(i);
                                             QThread::sleep(1);
                                         }
                                     })
            .subscribe_on(rxcpp::observe_on_event_loop())
            .observe_on(main_thread)
            .subscribe(
                    [&view](int i)
                    {
                        std::cout << " sb : " << i << "     " << std::this_thread::get_id() << std::endl;
                        if (i == 10)
                        {
                            view->hide();
                        }
                    });


}


void NetWorkManager::test(rxcpp::observe_on_one_worker &mainthread, LoginQuickView &view)
{



    rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> subscriber)
                                     {
                                         for (int i = 0; i < 100; i++)
                                         {
                                             std::cout << " ob : " << std::this_thread::get_id() << std::endl;
                                             subscriber.on_next(i);
                                             QThread::sleep(1);
                                         }
                                     })
            .subscribe_on(rxcpp::observe_on_event_loop())
            .observe_on(ThreadTool::getInstance()->main_thread)
            .subscribe(
                    [&view](int i)
                    {
                        std::cout << " sb : " << i << "     " << std::this_thread::get_id() << std::endl;
                        if (i == 5)
                        {

                        }

                        if (i == 10)
                        {

                            // view.hide();


                        }

                        if (i == 15)
                        {
                            //view.close();
                        }

                    });

}