import unittest.mock as mock
import pytest
import demo_recv.events


@pytest.mark.skip
def test_event_register() -> None:
    first_callback = mock.Mock()
    second_callback = mock.Mock()

    with pytest.raises(ValueError):
        demo_recv.events.register("Message", first_callback)

    demo_recv.events.register(demo_recv.events.EventTypes.Message, first_callback)
    result = demo_recv.events.get_event_callback(demo_recv.events.EventTypes.Message)
    assert result == [first_callback]

    demo_recv.events.register(demo_recv.events.EventTypes.Plot, second_callback)
    assert demo_recv.events.get_event_callback(demo_recv.events.EventTypes.Plot) == [second_callback]

    demo_recv.events.register(demo_recv.events.EventTypes.Message, second_callback)
    # the list is not guaranteed to be in the same order as inputted hence the set
    assert set(demo_recv.events.get_event_callback(demo_recv.events.EventTypes.Message)) == set([first_callback, second_callback])

    demo_recv.events.clear()
    assert demo_recv.events.get_event_callback(demo_recv.events.EventTypes.Plot) == []
    assert demo_recv.events.get_event_callback(demo_recv.events.EventTypes.Message) == []


@pytest.mark.skip
def test_event_notify() -> None:
    first_callback = mock.Mock()
    second_callback = mock.Mock()
    third_callback = mock.Mock()
    demo_recv.events.register(demo_recv.events.EventTypes.Message, first_callback)
    demo_recv.events.register(demo_recv.events.EventTypes.Plot, second_callback)
    demo_recv.events.register(demo_recv.events.EventTypes.Progress, third_callback)
    
    demo_recv.events.notify(demo_recv.events.EventTypes.Message, "Hello World")
    first_callback.assert_called_once_with("Hello World")
    second_callback.assert_not_called()

    data = demo_recv.events.PlotEventData()
    demo_recv.events.notify(demo_recv.events.EventTypes.Plot, data)
    first_callback.assert_called_once()
    second_callback.assert_called_once_with(data)

    data = demo_recv.events.ProgressEventData()
    demo_recv.events.notify(demo_recv.events.EventTypes.Progress, data)
    first_callback.assert_called_once()
    second_callback.assert_called_once()
    third_callback.assert_called_once_with(data)
    
    demo_recv.events.clear()
    demo_recv.events.notify(demo_recv.events.EventTypes.Message, "Hello World")
    demo_recv.events.notify(demo_recv.events.EventTypes.Plot, data)
    assert first_callback.call_count == 1
    assert second_callback.call_count == 1
    assert third_callback.call_count == 1
