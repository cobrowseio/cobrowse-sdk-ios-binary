((function() {

function trigger(el, EventType, event, params={}) {
    el.dispatchEvent(new EventType(event, { bubbles: true, cancelable: true, view: window, ...params }));
    if (typeof el[`on${event}`] === 'function') el[`on${event}`]();
}

function pick(x, y) {
    return document.elementFromPoint(x, y) || document;
}

function click(x, y) {
    if (document.activeElement) document.activeElement.blur();
    const el = pick(x, y);
    el.click();
    el.focus();
    trigger(el, MouseEvent, 'mouseover', {clientX: x, clientY:y});
    trigger(el, MouseEvent, 'mousedown', {clientX: x, clientY:y});
    trigger(el, MouseEvent, 'mouseup', {clientX: x, clientY:y});
    trigger(el, MouseEvent, 'click', {clientX: x, clientY:y});
}

function keypress({ key, code }) {
    const el = document.activeElement;
    if (!el) return;
    if (typeof el.value === 'undefined') return;
    
    const {  selectionStart, selectionEnd, value } = el;
    
    switch(key) {
        case 'Backspace':
            const start = (selectionStart === selectionEnd) ? selectionStart-1 : selectionStart;
            el.setRangeText('', start, selectionEnd, 'start');
        break;
        case 'ArrowLeft':
            el.setSelectionRange(selectionStart-1,  selectionStart-1);
        break;
        case 'ArrowRight':
            el.setSelectionRange(selectionEnd+1,  selectionEnd+1);
        break;
        case 'ArrowUp':
        case 'ArrowDown':
            // unsupported yet
        break;
        default:
            // if key length is > 1 then it's probably a modifer key press that
            // should be ignored
            if (key.length === 1) {
                if (selectionStart || selectionStart === 0) {
                    el.setRangeText(key, selectionStart, selectionEnd, 'end');
                } else {
                    el.setRangeText(key, el.value.length,  el.value.length);
                }
            }
        break;
    }
    
    trigger(el, KeyboardEvent, 'keydown', { key, code });
    trigger(el, KeyboardEvent, 'keypress', { key, code });
    trigger(el, KeyboardEvent, 'keyup', { key, code });
    trigger(el, InputEvent, 'input', { data: key });
    trigger(el, Event, 'change');
}

%@ // this will be replaced with the JS to run
})());
