let n;

let events_to_block = [
    "visibilitychange",
    "webkitvisibilitychange",
    "mozvisibilitychange",
    "hasFocus",
    "blur",
    "focus",
    "mouseleave"
]

array.forEach(element => {
    
});

for (let i = 0; i < events_to_block.length; i++) {
    let event_name = events_to_block[i];
    window.addEventListener(events_to_block[i], function (event) {
        event.stopImmediatePropagation();
    }, true);
}
