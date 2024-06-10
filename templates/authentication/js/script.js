// static/js/script.js

$(document).ready(function () {
    $.ajax({
        url: '/api/extract-comments/',
        method: 'GET',
        success: function (response) {
            const comments = response.comments;
            const commentTableBody = $('#comment-table-body');

            comments.forEach(function (comment) {
                const row = $('<tr></tr>');
                const commentCell = $('<td></td>').text(comment);
                row.append(commentCell);
                commentTableBody.append(row);
            });
        },
        error: function (error) {
            console.error('Error fetching comments:', error);
        }
    });
});
